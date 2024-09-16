from __future__ import annotations
import typing as t
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
        self.x_train: t.List[t.List[float]] = []
        self.y_train: t.List[int] = []
        self.distance_matrix: t.Callable[[t.List[float], t.List[float]], float] = (
            self.__euclidean_distance if mode == 0 else self.__manhattan_distance
        )

    def __euclidean_distance(self: KNN, x1: t.List[float], x2: t.List[float]) -> float:
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

    def __manhattan_distance(self: KNN, x1: t.List[float], x2: t.List[float]) -> float:
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

    def tune_model(self: KNN, k: int) -> None:
        self.k = k

    def predict_atom(self: KNN, x: t.List[float]) -> int:
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
        
        distances: t.List[t.Tuple[float]] = []

        for x_train in self.x_train:
            distance = self.distance_matrix(x, x_train)
            distances.append((x_train, distance))

        distances.sort(key=lambda x: x[1])

        k_nearest_neighbors = distances[:self.k]

        prediction = Counter(
            [self.y_train[self.x_train.index(x[0])] for x in k_nearest_neighbors]
        ).most_common(1)[0][0]

        return prediction

    def fit(self: KNN, x: t.List[t.List[float]], y: t.List[int]) -> None:
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
    
    def validate_accuracy(self: KNN, x: t.Tuple[t.List[float]], y: t.Tuple[int]) -> float:
        valid_count = 0
        
        for features, label in zip(x, y):
            prediction = self.predict_atom(features)
            if prediction == label:
                valid_count += 1

        return (valid_count / len(y)) * 100 

    def predict(self: KNN, X: t.List[t.List[float]]) -> t.List[int]:
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
    
    def model_accuracy(self: KNN, X: t.List[t.List[float]], y: t.List[int]) -> float:
        """
        Calculates the accuracy of the model on the provided test data.

        Parameters:
        ----------
        X : List[List[float]]
            The test data features (each sample is a list of features).
        y : List[int]
            The test data labels.

        Returns:
        -------
        float
            The accuracy of the model on the test data.
        """
        predictions = self.predict(X)
        correct_predictions = sum([1 for p, y_true in zip(predictions, y) if p == y_true])
        return (correct_predictions / len(y)) * 100
