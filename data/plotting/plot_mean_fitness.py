import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

csv_file_path = '../mean_fitness.csv'
data = pd.read_csv(csv_file_path, header = None)

plt.figure(figsize=(20, 10))
sns.set(style="whitegrid")
plt.ylim(0,1)

data = data.iloc[1:]

print(data)

plt.xlabel('Generation')
plt.ylabel('Mean fitness (unitless)')
plt.title('Mean fitness of infected hosts over generations')

plt.grid(True)
plt.plot(data.iloc[:])
plt.show()
