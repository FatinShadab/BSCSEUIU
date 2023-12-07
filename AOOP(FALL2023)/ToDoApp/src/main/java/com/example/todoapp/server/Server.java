package com.example.todoapp.server;

import com.example.todoapp.config.ServerConfig;
import javafx.scene.control.TextArea;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.*;

public class Server {
    private static ServerSocket serverSocket;
    private static Boolean active = false;
    private static Thread requestListeningThread;
    private static Boolean internalError = false;
    private final static HashMap<InetAddress, ArrayList<String[]>> clientData = new HashMap<>();
    private final static ArrayList<String> serverLogs = new ArrayList<>();
    private static TextArea loggingArea = null;

    public static void startListening() throws IOException {
        if (!active) {
            serverLogs.add("[~]["+ LocalDate.now().toString() +"] Server Started Listening.");
            writeLog(serverLogs.getLast());

            serverSocket = new ServerSocket(ServerConfig.serverPort);
            requestListeningThread = new Thread(new Runnable() {
                @Override
                public void run() {
                    while (active) {
                        try {
                            internalError = false;

                            Socket clientSocket = serverSocket.accept();

                            new Thread(() -> handleClientRequest(clientSocket)).start();
                        }
                        catch (SocketException se) {
                            if (!serverSocket.isClosed()) {
                                break;
                            }
                        }
                        catch (Throwable throwable) {
                            serverLogs.add("[!]["+ LocalDate.now().toString() +"] Exception : " + throwable.toString());
                            writeLog(serverLogs.getLast());
                            for (StackTraceElement t : throwable.getStackTrace()) {
                                System.out.println("\t[!] " + t.toString());
                            }
                            internalError = true;
                        }
                    }
                }
            });
            requestListeningThread.start();
            active = true;
        }

        if (internalError) throw new IOException();
    }

    public static void stopListening() throws Exception{
        serverLogs.add("[~]["+ LocalDate.now().toString() +"] Server Stopped Listening.");
        writeLog(serverLogs.getLast());
        active = false;
        requestListeningThread = null;
        serverSocket.close();
    }

    private static void handleClientRequest(Socket clientSocket) {
        serverLogs.add("[~]["+ LocalDate.now().toString() +"] Client joined, client address : " + clientSocket.getInetAddress().getHostAddress());
        writeLog(serverLogs.getLast());

        try{
            ObjectInputStream inputStream = new ObjectInputStream(clientSocket.getInputStream());
            ObjectOutputStream outputStream = new ObjectOutputStream (clientSocket.getOutputStream());

            clientData.computeIfAbsent(clientSocket.getInetAddress(), k -> new ArrayList<String[]>());

            if (clientData.get(clientSocket.getInetAddress()) != null)
                clientData.get(clientSocket.getInetAddress()).add((String[]) inputStream.readObject());

            Collections.sort(
                    clientData.get(clientSocket.getInetAddress()),
                    new Comparator<String[]>() {
                        @Override
                        public int compare(String[] o1, String[] o2) {
                            LocalDate date1 = LocalDate.parse(o1[1]);
                            LocalDate date2 = LocalDate.parse(o2[1]);

                            return date1.compareTo(date2);
                        }
                    }
            );

            serverLogs.add("[~]["+ LocalDate.now().toString() +"] Client : (" + clientSocket.getInetAddress().getHostAddress() + ") added task !");
            writeLog(serverLogs.getLast());

            outputStream.writeObject(clientData.get(clientSocket.getInetAddress()));
        }
        catch (Throwable throwable) {
            serverLogs.add("[!]["+ LocalDate.now().toString() +"] Exception : " + throwable.toString());
            writeLog(serverLogs.getLast());
            for (StackTraceElement t : throwable.getStackTrace()) {
                System.out.println("\t[!] " + t.toString());
            }
        }
    }

    public static ArrayList<String> getServerLogs() {
        return serverLogs;
    }

    public static void setLoggingArea(TextArea loggingArea) {
        Server.loggingArea = loggingArea;
    }

    private static void writeLog(String log) {
        if (loggingArea == null) return;
        loggingArea.setText(loggingArea.getText() + "\n" + log);
    }

    public static void saveLogs() throws IOException{
        Path path = Paths.get(ServerConfig.logFileDirPath);

        if (!(Files.exists(path))){
            Files.createDirectory(path);
        }

        String filePath = path.toString() + "/server_log_"+ LocalDateTime.now().toString().replace(':', '_').replace('.', '_').replace('/', '_') +".txt";

        new File(filePath);

        FileWriter fileWriter = new FileWriter(filePath);

        for (String log : serverLogs) {
            fileWriter.write(log + "\n");
        }

        fileWriter.close();
    }
}
