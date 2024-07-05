import copy
import math
import random
from datetime import datetime


class GeneticAlgorithm:
    def __init__(self):
        self.genes = []
        self.gnomeSelection = {"atomic": 0, 
                               "chunk": 1
                            }
    
    def __tune_random(self):
        random.seed(math.sqrt(abs(datetime.now().microsecond - datetime.now().second)))

    def is_ready(self):
        return self.genes != None
    
    def set_genes(self, genes):
        if type(genes) == str:
            self.genes = [g for g in genes]
        else:
            self.genes = genes
    
    def trigger_mutation(self, gnome):
        if not self.is_ready(): raise Exception("Broken Configuration !")
        self.__tune_random()
        
        __g = copy.deepcopy(self.genes) 
        mutatedGnome = gnome
        gene2bMutated = random.choice(range(len(gnome)))
        __g.remove(mutatedGnome[gene2bMutated])
        
        mutatedGnome[gene2bMutated] = random.choice(__g)
        
        return mutatedGnome
       
    def crossover(self, chromosoms, gnomeSelectionMode=0):
        if not self.is_ready(): raise Exception("Broken Configuration !")
        
        self.__tune_random()
        
        chromosom1, chromosom2 = chromosoms
        
        newChromosom = []
        
        if gnomeSelectionMode == self.gnomeSelection["atomic"]:
            for gC1, gC2 in zip(chromosom1, chromosom2):
                    self.__tune_random()
                    selectionProb = random.random()
                    
                    if selectionProb < 0.45:
                        newChromosom.append(gC1)
                    elif selectionProb < 0.89:
                        newChromosom.append(gC2)
                    else:
                        chromosomSet = chromosom1 + chromosom2
                        random.shuffle(chromosomSet)
                        newChromosom.append(random.choice(chromosomSet))
        
        elif gnomeSelectionMode == self.gnomeSelection["chunk"]:
            equatorLineIdx = random.choice(range(1, len(chromosom1)))
            
            newChromosom = chromosom1[:equatorLineIdx]
            newChromosom += chromosom2[equatorLineIdx:]
        
        return self.trigger_mutation(newChromosom)