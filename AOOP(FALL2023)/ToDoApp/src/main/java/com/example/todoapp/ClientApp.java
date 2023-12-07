package com.example.todoapp;

import com.example.todoapp.config.ClientConfig;
import com.example.todoapp.config.ServerConfig;
import com.example.todoapp.manager.SceneManager;
import javafx.application.Application;
import javafx.stage.Stage;

import java.io.IOException;

public class ClientApp extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        ClientConfig.configWindow(stage);

        try {
            SceneManager.setScene(
                    "/clientUI/clientHomeScene.fxml",
                    ServerConfig.windowWidth,
                    ServerConfig.windowHeight,
                    stage
            );
        } catch (Throwable throwable) {
            System.out.println("[!] Exception : " + throwable.toString());
            for (StackTraceElement t : throwable.getStackTrace()) {
                System.out.println("\t[!] " + t.toString());
            }
        }
    }

    public static void main(String[] args) {
        launch();
    }
}