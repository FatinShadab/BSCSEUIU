package com.example.todoapp.config;

import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Objects;

public class ServerConfig extends AbstractAppConfig {
    private final static String windowTitle = "Server";
    private final static String iconSrcPath = "/images/serverLogo.png";
    public final static Integer serverPort = 8080;
    public final static String serverIp = "localhost";
    public final static String logFileDirPath = Paths.get(System.getProperty("user.dir"), "src", "main", "server_data").toString();

    public static void configWindow(Stage stage) {
        AbstractAppConfig.configWindow(stage, windowTitle, iconSrcPath);
    }
}
