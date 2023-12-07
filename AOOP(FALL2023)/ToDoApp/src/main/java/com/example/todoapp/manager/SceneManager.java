package com.example.todoapp.manager;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class SceneManager {
    public static void setScene(String sceneSrcPath, double sceneWidth, double sceneHeight, ActionEvent referenceEvent) throws Exception {
        FXMLLoader fxmlLoader = new FXMLLoader(SceneManager.class.getResource(sceneSrcPath));
        Parent componentTreeRoot = fxmlLoader.load();
        Scene scene = new Scene(componentTreeRoot, sceneWidth, sceneHeight);

        Node referenceEventSourceNode = (Node) referenceEvent.getSource();
        Scene referenceNodeSourceScene = referenceEventSourceNode.getScene();
        Stage sceneStage = (Stage) referenceNodeSourceScene.getWindow();

        sceneStage.setScene(scene);
        sceneStage.show();
    }

    public static void setScene(String sceneSrcPath, double sceneWidth, double sceneHeight, Stage appStage) throws Exception {
        FXMLLoader fxmlLoader = new FXMLLoader(SceneManager.class.getResource(sceneSrcPath));
        Parent componentTreeRoot = fxmlLoader.load();
        Scene scene = new Scene(componentTreeRoot, sceneWidth, sceneHeight);

        appStage.setScene(scene);
        appStage.show();
    }
}