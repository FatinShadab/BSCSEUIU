package com.example.todoapp.client;

import com.example.todoapp.config.ServerConfig;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;

public class Client {
    private static ArrayList<String[]> recivedData;

    public static void sendData(String task, String date) throws Exception {
        Socket requestSocket = new Socket(ServerConfig.serverIp, ServerConfig.serverPort);

        ObjectOutputStream outputStream = new ObjectOutputStream(requestSocket.getOutputStream());
        ObjectInputStream inputStream = new ObjectInputStream(requestSocket.getInputStream());
        String[] data = {
                task,
                date
        };
        outputStream.writeObject(data);
        recivedData = (ArrayList<String[]>) inputStream.readObject();
    }

    public static ArrayList<String[]> getReceivedData() {
        return recivedData;
    }
}
