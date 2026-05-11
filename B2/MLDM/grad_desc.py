a = 0
b = 0
alpha = 10 ** -4 # increase/decrease the value of alpha to fine-tune the model. 10^-4 is the sweet spot in this case
x = [30, 43, 25, 51, 40, 20]
y = [2.5, 3.4, 1.8, 4.5, 3.2, 1.6]
m = 6
iteration = 0
iteration_count = 10
cost_func = 0

def calculate_cost_func():
    global cost_func
    for i in range (m):
        cost_func += 1/(2*m) * ((a * x[i] + b - y[i]) ** 2)

calculate_cost_func()
print(f"Iteration {iteration}: a = {round(a, 6)}, b = {round(b, 6)}, cost function = {round(cost_func, 6)}")

for i in range (iteration_count):
    iteration += 1
    dEa = 0
    dEb = 0
    cost_func = 0
    for j in range (m):
        dEa += 1/m * (a * x[j] + b - y[j]) * x[j]
    for j in range (m):
        dEb += 1/m * (a * x[j] + b - y[j])
    a -= alpha * dEa
    b -= alpha * dEb
    calculate_cost_func()
    print(f"Iteration {iteration}: a = {round(a, 6)}, b = {round(b, 6)}, cost function = {round(cost_func, 6)}")
