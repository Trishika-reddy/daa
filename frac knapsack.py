def fractional_knapsack(value, weight, capacity):
   

    # Calculate the value per unit weight of each item
    value_per_weight = [(value[i] / weight[i], i) for i in range(len(value))]
    # Sort items based on value per unit weight in decreasing order
    value_per_weight.sort(reverse=True)

    # Initialize variables
    total_value = 0
    fractions = [0] * len(value)

    for vp, i in value_per_weight:
        if weight[i] <= capacity:
            # Add the whole item if it fits
            fractions[i] = 1
            total_value += value[i]
            capacity -= weight[i]



        else:
            # Add a fraction of the item otherwise
            fraction = capacity / weight[i]
            fractions[i] = fraction
            total_value += value[i] * fraction
            break  # we have filled the knapsack completely

    return total_value, fractions
value = [60, 100, 120]
weight = [10, 20, 30]
capacity = 50

total_value, fractions = fractional_knapsack(value, weight, capacity)
print("Total value of items in the knapsack =", total_value)
print("Fractions of items in the knapsack =", fractions)
