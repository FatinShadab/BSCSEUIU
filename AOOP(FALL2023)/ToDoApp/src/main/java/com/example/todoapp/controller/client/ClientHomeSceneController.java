package com.example.todoapp.controller.client;

import com.example.todoapp.client.Client;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.Pane;

import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

public class ClientHomeSceneController implements Initializable {
    public static class DataRow {
        private final Integer index;
        private final String taskTimeStamp;
        private final String task;

        public DataRow(Integer index, String taskTimeStamp, String task) {
            this.index = index;
            this.taskTimeStamp = taskTimeStamp;
            this.task = task;
        }

        public Integer getIndex() {
            return index;
        }

        public String getTaskTimeStamp() {
            return taskTimeStamp;
        }

        public String getTask() {
            return task;
        }
    }

    @FXML
    TextField taskInputField;
    @FXML
    Button addTaskButton;
    @FXML
    Pane internalServerErrorPane;
    @FXML
    TableView<DataRow> tableView;
    @FXML
    DatePicker datePicker;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        addTaskButton.setDisable(true);
        internalServerErrorPane.setVisible(false);

        TableColumn<DataRow, Integer> indexColumn = new TableColumn<>("ID");
        indexColumn.setCellValueFactory(new PropertyValueFactory<>("index"));

        TableColumn<DataRow, String> timeStampColumn = new TableColumn<>("Time stamp");
        timeStampColumn.setCellValueFactory(new PropertyValueFactory<>("taskTimeStamp"));

        TableColumn<DataRow, String> taskColumn = new TableColumn<>("Task");
        taskColumn.setCellValueFactory(new PropertyValueFactory<>("task"));

        tableView.getColumns().addAll(indexColumn, timeStampColumn, taskColumn);
    }

    public void onAddTaskButtonClicked() {
        try {
            Client.sendData(taskInputField.getText(), datePicker.getValue().toString());
            updateTableData(Client.getReceivedData());
        } catch (Throwable throwable) {
            System.out.println("[!] Exception : " + throwable.toString());
            for (StackTraceElement t : throwable.getStackTrace()) {
                System.out.println("\t[!] " + t.toString());
            }
            internalServerErrorPane.setVisible(true);
        }
    }

    public void setDisablePropertyOfAddTaskButton() {
        addTaskButton.setDisable(taskInputField.getText().isEmpty() || datePicker.getValue() == null);
    }

    public void onServerErrorOkButtonClicked() {
        internalServerErrorPane.setVisible(false);
    }

    public void updateTableData(ArrayList<String[]> data) {
        tableView.getItems().clear();
        for (int i = 0; i < data.size(); i++) {
            DataRow __data = new DataRow(i, data.get(i)[1], data.get(i)[0]);
            tableView.getItems().add(__data);
        }
    }
}
