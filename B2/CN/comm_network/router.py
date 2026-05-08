# note:this work is for the exercises of chapter 4, part 2 

class Router:
    def __init__(self) -> None:
        self.id: str = ""
        self.neighbors: list = [""]
        self.routing_table: list = [[]]
    def init_table(self):
        pass
    def update_distance_vector(self):
        pass
    def run_link_state(self):
        pass
    def print_routing_table(self):
        pass

class Network:
    def __init__(self, matrix, routers) -> None:
        self.matrix: list = matrix
        self.routers: list = routers
    def build_network(self):
        pass
    def run_distance_vector(self):
        pass
    def run_link_state(self):
        pass
    def print_all_tables(self):
        pass

def main():
    temp_matrix: list = [[0, 2, 5, -1, -1], [2, 0, 1, 2, 1], [5, 0, 1, 3, 1], [-1, 2, 3, 0, 2], [-1, -1, 1, 2, 0]]
    network: Network = Network(temp_matrix, [])
    for i in range(5):
        network.routers[i] =  Router()
    
    