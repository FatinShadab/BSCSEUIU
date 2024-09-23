import os
import numpy as np
from sklearn.datasets import make_blobs
from kmc import KMC


if __name__ == "__main__":
    k = 3
    Kmean = KMC(k=k)

    # Generate data
    data = make_blobs(n_samples=500, centers=k, n_features=2, random_state=42)
    # Fit data
    Kmean.fit(data)

    # Generate centroids
    Kmean.tune(epochs=10, show=True, pause=False)

    for cluster in Kmean.clusters_archive:
        print(cluster)

    cluster_index = int(input("Enter cluster index: "))

    # Predict
    predictions = Kmean.predict(data[0], cluster_index)
    predictions = [int(i) for i in predictions]
    print(predictions)
    Kmean.show_predict(data[0], cluster_index)


    input("Press Enter to exit...")
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')