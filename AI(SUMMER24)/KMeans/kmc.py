import random
import numpy as np
import threading
import matplotlib.pyplot as plt

class KMC:
    def __init__(self, k, k_marker='^'):
        self.k = k
        self.k_marker = k_marker
        self.X, self.y = None, None
        self.clusters = {}
        self.clusters_archive = []

    def __check_config(self):
        if self.X is None or self.y is None:
            raise Exception("Data not found")

    def fit(self, data):
        self.X, self.y = data

    def distance(self, p1, p2):
        return np.sqrt(np.sum((p1 - p2)**2))

    def assign_clusters(self):
        self.__check_config()
        for point in self.X:
            distances = [self.distance(point, cluster['center']) for cluster in self.clusters.values()]
            cluster_index = np.argmin(distances)
            self.clusters[cluster_index]['points'].append(point)

    def update_clusters(self, show=False, block=True, name=None):
        for cluster in self.clusters.values():
            if cluster['points']:
                cluster['center'] = np.mean(cluster['points'], axis=0)
            else:
                print("Cluster has no points, keeping previous center.")

            cluster['points'] = []

        if show:
            self.show(data_points=[cluster['center'] for cluster in self.clusters.values()], block=block, name=name)

    def generate_centroids(self, spread_value=2, show=False):
        np.random.seed(random.randint(0, 100))
        self.__check_config()

        for k in range(self.k):
            center = spread_value*(2*np.random.random(self.X.shape[1])-1)
            cluster = {
                'center': center,
                'points': []
            }
            self.clusters[k] = cluster

        if show:
            self.show(data_points=[cluster['center'] for cluster in self.clusters.values()])

    def tune(self, epochs=100, show=False, pause=False):
        self.__check_config()
        for epoch in range(epochs):
            if pause:
                input(f"Press Enter to continue to epoch: {epoch}...")
            self.generate_centroids(show=False)
            self.assign_clusters()
            self.update_clusters(show=show, block=False, name=f"Epoch: {epoch}")
            self.clusters_archive.append(self.clusters)
            self.clusters = {}

    def predict_atom(self, data, cluster_index=None):
        self.__check_config()
        if cluster_index is not None and cluster_index < len(self.clusters_archive):
            clusters = self.clusters_archive[cluster_index]
            distances = [self.distance(data, cluster['center']) for cluster in clusters.values()]
        else:
            distances = [self.distance(data, cluster['center']) for cluster in self.clusters.values()]
        cluster_index = np.argmin(distances)

        return int(cluster_index)

    def predict(self, data, cluster_index):
        return [self.predict_atom(point, cluster_index) for point in data]

    def show_predict(self, data, cluster_index):
        self.__check_config()
        predictions = self.predict(data, cluster_index)
        plt.figure()

        plt.gcf().canvas.manager.set_window_title("Predictions")

        plt.scatter(self.X[:, 0], self.X[:, 1], cmap='viridis', c=predictions)
        
        for cluster in self.clusters_archive[cluster_index].values():
            plt.scatter(*cluster['center'], marker=self.k_marker, c='red')
        
        plt.grid(True)
        plt.show()

    def show(self, data_points=None, block=True, name=None):
        self.__check_config()
        
        plt.figure()

        if name:
            plt.gcf().canvas.manager.set_window_title(name)

        plt.scatter(self.X[:, 0], self.X[:, 1], c=self.y, cmap='viridis')

        if data_points is not None:
            for data_point in data_points:
                if isinstance(data_point, (np.ndarray, list)) and len(data_point) == 2:
                    plt.scatter(data_point[0], data_point[1], marker=self.k_marker, c='red')
                else:
                    print(f"Invalid data_point: {data_point}, skipping.")
        
        plt.grid(True)

        if block:
            plt.show()
        else:
            plt.ion()