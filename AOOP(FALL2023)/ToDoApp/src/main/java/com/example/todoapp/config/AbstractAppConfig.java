package com.example.todoapp.config;

import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.util.Objects;

public abstract class AbstractAppConfig {
    public static Double windowHeight = 720.00;
    public static Double windowWidth = 1080.00;

    public static void configWindow(Stage stage, String windowTitle, String iconSrcPath) {
        stage.setWidth(windowWidth);
        stage.setHeight(windowHeight);
        stage.setTitle(windowTitle);
        stage.getIcons().add(new Image(Objects.requireNonNull(ServerConfig.class.getResourceAsStream(iconSrcPath))));
    }
}
