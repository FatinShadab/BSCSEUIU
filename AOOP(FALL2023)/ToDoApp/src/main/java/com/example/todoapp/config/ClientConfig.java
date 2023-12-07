package com.example.todoapp.config;

import javafx.stage.Stage;


public class ClientConfig extends AbstractAppConfig {
    private final static String windowTitle = "Do.It";
    private final static String iconSrcPath = "/images/clientAppLogo.png";

    public static void configWindow(Stage stage) {
        AbstractAppConfig.configWindow(stage, windowTitle, iconSrcPath);
    }
}
