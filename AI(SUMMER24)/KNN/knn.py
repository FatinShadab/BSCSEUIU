from __future__ import annotations
import typing as type
from collections import Counter

class KNN:
    """
    K-Nearest Neighbors (KNN) classifier implementation.

    Parameters:
    ----------
    k : int
        The number of nearest neighbors to consider for classification.
    mode : int
        The distance metric to use:
        - 0: Euclidean distance
        - 1: Manhattan distance

    Methods:
    -------
    fit(x: List[List[float]], y: List[int]) -> None
        Fits the model with the provided training data.
    predict(X: List[List[float]]) -> List[int]
        Predicts the labels for the provided test data based on the k nearest neighbors.
    
    Private Methods:
    ---------------
    __euclidean_distance(x1: List[float], x2: List[float]) -> float
        Calculates the Euclidean distance between two points.
    __manhattan_distance(x1: List[float], x2: List[float]) -> float
        Calculates the Manhattan distance between two points.
    __predict_atom(x: List[float]) -> int
        Predicts the label for a single sample based on the k nearest neighbors.
    """

    def __init__(self: KNN, k: int, mode: int) -> None:
        """
        Initializes the KNN classifier with a specified value of k and distance metric.

        Parameters:
        ----------
        k : int
            The number of nearest neighbors to consider for classification.
        mode : int
            The distance metric to use (0 for Euclidean, 1 for Manhattan).
        """
        self.k: int = k
        self.x_train: type.List[type.List[float]] = []
        self.y_train: type.List[int] = []
        self.distance: type.Callable[[type.List[float], type.List[float]], float] = (
            self.__euclidean_distance if mode == 0 else self.__manhattan_distance
        )

    def __euclidean_distance(self: KNN, x1: type.List[float], x2: type.List[float]) -> float:
        """
        Computes the Euclidean distance between two points.

        Parameters:
        ----------
        x1 : List[float]
            The first point (a list of features).
        x2 : List[float]
            The second point (a list of features).

        Returns:
        -------
        float
            The Euclidean distance between the two points.
        """
        return sum((x1_i - x2_i) ** 2 for x1_i, x2_i in zip(x1, x2)) ** 0.5

    def __manhattan_distance(self: KNN, x1: type.List[float], x2: type.List[float]) -> float:
        """
        Computes the Manhattan distance between two points.

        Parameters:
        ----------
        x1 : List[float]
            The first point (a list of features).
        x2 : List[float]
            The second point (a list of features).

        Returns:
        -------
        float
            The Manhattan distance between the two points.
        """
        return sum(abs(x1_i - x2_i) for x1_i, x2_i in zip(x1, x2))

    def predict_atom(self: KNN, x: type.List[float]) -> int:
        """
        Predicts the label for a single test sample based on the k nearest neighbors.

        Parameters:
        ----------
        x : List[float]
            A test sample (a list of features).

        Returns:
        -------
        int
            The predicted label for the test sample.
        """
        if len(self.x_train) != len(self.y_train):
            raise ValueError("The length of x_train and y_train must be equal.")
        
        # Calculate distances between the test sample and all training samples
        distances: type.List[float] = [self.distance(x, x_train) for x_train in self.x_train]

        # Get the indices of the k nearest neighbors
        k_indices: type.List[int] = sorted(range(len(distances)), key=lambda i: distances[i])[:self.k]

        # Get the labels of the k nearest neighbors
        k_near_labels: type.List[int] = [self.y_train[i] for i in k_indices]

        # Return the most common label among the nearest neighbors
        return Counter(k_near_labels).most_common(1)[0][0]

    def fit(self: KNN, x: type.List[type.List[float]], y: type.List[int]) -> None:
        """
        Trains the KNN model using the provided training data.

        Parameters:
        ----------
        x : List[List[float]]
            The training data features (each sample is a list of features).
        y : List[int]
            The training data labels.
        """
        self.x_train = x
        self.y_train = y
    
    def validate(self: KNN, x: type.List[type.List[float]], y: type.List[int]) -> float:
        """
        Validates the model using the provided validation data.

        Parameters:
        ----------
        x : List[List[float]]
            The validation data features (each sample is a list of features).
        y : List[int]
            The validation data labels.

        Returns:
        -------
        float
            The accuracy of the model on the validation data.
        """
        y_pred: type.List[int] = self.predict(x)
        return (sum(y_i == y_pred_i for y_i, y_pred_i in zip(y, y_pred)) / len(y)) * 100

    def predict(self: KNN, X: type.List[type.List[float]]) -> type.List[int]:
        """
        Predicts the labels for the provided test data.

        Parameters:
        ----------
        X : List[List[float]]
            The test data (each sample is a list of features).

        Returns:
        -------
        List[int]
            The predicted labels for the test data.
        """
        return [self.predict_atom(x) for x in X]
