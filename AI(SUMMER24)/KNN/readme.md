# Student Section Classification Using K-Nearest Neighbors (KNN)

This project classifies students into sections `A` or `B` based on their assignment marks, midterm, and final scores using the K-Nearest Neighbors (KNN) algorithm. The dataset contains students' roll numbers, assignment scores, midterm, final exam marks, and their section labels.

## Dataset

The dataset (`dataset.csv`) contains the following columns:

- **Roll**: Student roll number
- **Assignment-1**: Marks for Assignment 1 (0-15)
- **Assignment-2**: Marks for Assignment 2 (0-15)
- **Assignment-3**: Marks for Assignment 3 (0-15)
- **Assignment-4**: Marks for Assignment 4 (0-15)
- **Assignment-5**: Marks for Assignment 5 (0-15)
- **Final**: Final exam marks (0-60)
- **Mid**: Midterm exam marks (0-25)
- **Section**: Section label (`A` or `B`)

## Objective

The goal is to predict whether a student belongs to section `A` or `B` using the K-Nearest Neighbors algorithm. The performance of KNN will be evaluated using different values of `k` (1, 2, 3) to determine which value provides the best accuracy.

## Steps

1. **Data Loading and Splitting**  
   Load the dataset and split it into three subsets:
   - **Training Set**: 80% of the data
   - **Validation Set**: 10% of the data
   - **Testing Set**: 10% of the data

2. **Normalization**  
   Normalize all numerical columns (Assignment-1 to Assignment-5, Final, Mid) to bring the values into the range [0, 1] using the formula:  
   \[
   \text{normalized value} = \frac{x - x_{\min}}{\text{range}}
   \]
   where:
   - \(x\) is the original value
   - \(x_{\min}\) is the minimum value in the column
   - range = \(x_{\max} - x_{\min}\)

3. **K-Nearest Neighbors (KNN) Algorithm**  
   For each sample \(V\) in the **validation set**:
   - For each sample \(T\) in the **training set**:
     - Calculate the Euclidean distance between \(V_x\) (features from columns 1 to N-1) and \(T_x\) (features from columns 1 to N-1).
     - Store the distance and the corresponding training sample \(T\) in a list \(L\).
   - Sort the list \(L\) in ascending order of distance.
   - Take the first \(K\) samples (smallest distances).
   - Determine the majority class from the \(K\) samples (this is the predicted section for sample \(V\)).

4. **Accuracy Calculation**  
   Calculate the validation accuracy using the formula:  
   \[
   \text{validation\_accuracy} = \frac{\text{correct validation samples}}{\text{total validation samples}} \times 100
   \]
   Repeat the above steps for different values of \(K = 1, 2, 3\) and check which value of \(K\) gives the best validation accuracy.

5. **Test Set Accuracy**  
   After selecting the best \(K\) based on validation accuracy, calculate the accuracy on the **test set** using the same process.

## Pseudo Code

```python
# For each sample V in the VALIDATION set:
for V in VALIDATION:
    L = []
    # For each sample T in the TRAINING set:
    for T in TRAINING:
        # Calculate Euclidean distance between V and T
        distance = euclidean_distance(V, T)
        L.append((T, distance))
    
    # Sort L by ascending order of distance
    L.sort(key=lambda x: x[1])
    
    # Take the first K samples
    K_samples = L[:K]
    
    # Determine the majority class from the K samples
    predicted_class = majority_class(K_samples)
    
    # Check if the prediction is correct
    if predicted_class == V.section:
        correct_predictions += 1

# Calculate validation accuracy
validation_accuracy = (correct_predictions / len(VALIDATION)) * 100
```

## Evaluation

- Perform the above algorithm for \(K = 1, 2, 3\).
- Select the best value of \(K\) based on the validation accuracy.
- Calculate the test set accuracy using the chosen value of \(K\).
