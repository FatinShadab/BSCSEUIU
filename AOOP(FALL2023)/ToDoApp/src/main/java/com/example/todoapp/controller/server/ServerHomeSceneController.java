package com.example.todoapp.controller.server;

import com.example.todoapp.server.Server;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.layout.Pane;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class ServerHomeSceneController implements Initializable {
    @FXML
    Button startButton, stopButton;
    @FXML
    Pane internalServerErrorPane;
    @FXML
    TextArea logsTextArea;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        logsTextArea.setEditable(false);
        stopButton.setDisable(true);
        internalServerErrorPane.setVisible(false);
        Server.setLoggingArea(logsTextArea);
    }

    public void onStartButtonClicked() {
        try {
            Server.startListening();
            stopButton.setDisable(false);
            startButton.setDisable(true);
        } catch (Throwable throwable) {
            System.out.println("[!] Exception : " + throwable.toString());
            for (StackTraceElement t : throwable.getStackTrace()) {
                System.out.println("\t[!] " + t.toString());
            }
            internalServerErrorPane.setVisible(true);
        }
    }

    public void onStopButtonClicked() {
        try {
            Server.stopListening();
            startButton.setDisable(false);
        } catch (Throwable throwable) {
            System.out.println("[!] Exception : " + throwable.toString());
            for (StackTraceElement t : throwable.getStackTrace()) {
                System.out.println("\t[!] " + t.toString());
            }
            internalServerErrorPane.setVisible(true);
        }
    }

    public void onSaveLogButtonClicked() throws IOException {
        Server.saveLogs();
    }

    public void onServerErrorOkButtonClicked() {
        internalServerErrorPane.setVisible(false);
    }
}
