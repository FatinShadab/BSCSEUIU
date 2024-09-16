import csv
from random import shuffle
import typing as t
from knn import KNN

CLASS_MAP = {'A': 0, 'B': 1}

def load_data(file_path: str) -> t.Tuple[t.List[t.List[float]], t.List[int]]:
    """
    Loads the data from the specified file.

    Parameters:
    ----------
    file_path : str
        The path to the file containing the data.

    Returns:
    -------
    x : List[List[float]]
        The feature vectors of the data.
    y : List[int]
        The labels of the data.
    """
    x: t.List[t.List[float]] = []
    y: t.List[int] = []

    with open(file_path, "r") as file:
        reader = csv.reader(file)
        next(reader)  # Skip the header
        for row in reader:
            x.append([int(val) for val in row[:-1]])
            y.append(row[-1])

    return x, y

def suffle_data(x: t.List[t.List[float]], y: t.List[int]) -> t.Tuple[t.List[t.List[float]], t.List[int]]:
    """
    Shuffles the data.

    Parameters:
    ----------
    x : List[List[float]]
        The feature vectors of the data.
    y : List[int]
        The labels of the data.

    Returns:
    -------
    Tuple[List[List[float]], List[int]]
        The shuffled feature vectors and labels.
    """
    data = list(zip(x, y))
    shuffle(data)
    x, y = zip(*data)
    return x, y

def get_clean_data(x: t.List[t.List[float]], y: t.List[int]) -> t.Tuple[t.List[t.List[float]], t.List[int]]:
    """
    Cleans the data by removing any rows with missing values.

    Parameters:
    ----------
    x : List[List[float]]
        The feature vectors of the data.
    y : List[int]
        The labels of the data.

    Returns:
    -------
    Tuple[List[List[float]], List[int]]
        The cleaned feature vectors and labels.
    """
    clean_x: t.List = []
    clean_y: t.List = []

    for idx, row in enumerate(x):
        clean_x.append(row[1:])
        clean_y.append(CLASS_MAP[y[idx]])

    return clean_x, clean_y

def get_normalized_data(x: t.List):
    """
     Normalize specified columns in the data to a [0, 1] range.

    Parameters:
    ----------
    x : List
        The vector.

    Returns:
    -------
    list
        The norm form of the data.
    """
    if type(x[0]) is not list:
        x = [(e/100)%1 for e in x]
        return x
    
    cols = len(x[0])

    for col in range(cols):
        column = [row[col] for row in x]
        min_val = min(column)
        max_val = max(column)
        range_val = max_val - min_val

        for row in x:
            if range_val == 0:
                row[col] = 0
            else:
                row[col] = (row[col] - min_val) / range_val
                row[col] = round(float(max(0, min(1, row[col]))), 2)

    return x

def split_train_val_test_data(x: t.Tuple, y:t.Tuple, ratio: t.Tuple) -> t.Tuple:
    """
    Splits the dataset into training, validation, and test sets based on the provided ratio.
    Args:
        ratio (tuple): A tuple containing three float values that represent the ratio for 
                       splitting the dataset into training, validation, and test sets respectively.
                       The sum of the values should be equal to 1.0.
    Returns:
        tuple: A tuple containing three datasets (train, validation, test) after splitting.
    """
    if sum(ratio) != 1.0 and len(ratio) != 3:
        raise ValueError("The sum of the ratio values should be equal to 1.0.")
    if len(x) != len(y):
        raise ValueError("The length of x and y must be equal")
                         
    data_count = len(x)
    train_count = int(data_count * ratio[0])
    val_count = int(data_count * ratio[1])

    train_x: t.List = x[:train_count]
    train_y: t.List = y[:train_count]

    val_x: t.List = x[train_count:train_count + val_count]
    val_y: t.List = y[train_count:train_count + val_count]

    test_x: t.List = x[train_count + val_count:]
    test_y: t.List = y[train_count + val_count:]

    return ((train_x, train_y), (val_x, val_y), (test_x, test_y))


if __name__ == "__main__":
    model_banchmark = {}
    x, y = load_data("dataset.csv")
    x, y = get_clean_data(x, y)
    x = get_normalized_data(x)
    x, y = suffle_data(x, y)

    train_dataset, val_dataset, test_dataset = split_train_val_test_data(x, y, (0.8, 0.1, 0.1))

    print("Data Split Information:")
    print("----------------")
    print("Train Data:")
    print(train_dataset)
    print("----------------")
    print("Validation Data:")
    print(val_dataset)
    print("----------------")
    print("Test Data:")
    print(test_dataset)
    print("----------------")

    mode = 0
    model = KNN(10, mode)
    model.fit(train_dataset[0], train_dataset[1])

    print("Model Information:")
    #print(model.x_train)
    #print(model.y_train)

    for k in range(1, 4):
        model.tune_model(k)
        accuracy = model.validate_accuracy(val_dataset[0], val_dataset[1])
        model_banchmark[k] = accuracy

    #print(model_banchmark)

    best_k = 1
    for k, accuracy in model_banchmark.items():
        if accuracy > model_banchmark[best_k]:
            best_k = k

    #print(f"Best k: {best_k}")

    model.tune_model(best_k)
    #print(model.k)
    accuracy = model.model_accuracy(test_dataset[0], test_dataset[1])
    #print(accuracy)

    print("Model Information:")
    print("----------------")
    print(f"Model Banchmark: {model_banchmark}")
    print(f"Best k: {best_k}")
    print(f"Validation Accuracy: {model_banchmark[best_k]}")
    print(f"Test Accuracy: {accuracy}")
    print("Model Configuration:")
    print("----------------")
    print(f"Number of Neighbors (k): {model.k}")
    print(f"Distance Metric: {'Euclidean' if mode == 0 else 'Manhattan'}")