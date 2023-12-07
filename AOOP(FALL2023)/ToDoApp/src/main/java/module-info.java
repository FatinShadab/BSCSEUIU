module com.example.todoapp {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.todoapp to javafx.fxml;
    exports com.example.todoapp;
    opens com.example.todoapp.controller.server to javafx.fxml;
    exports com.example.todoapp.controller.server;
    opens com.example.todoapp.controller.client to javafx.fxml;
    exports com.example.todoapp.controller.client;
}