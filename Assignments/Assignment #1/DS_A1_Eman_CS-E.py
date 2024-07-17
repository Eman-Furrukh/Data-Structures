#!/usr/bin/env python
# coding: utf-8

# # Eman Furrukh 21i-1726 CS-E

# # DATA STRUCTURES

# # ASSIGNMENT # 1

# # Q1)

# In[1]:


import pandas as pd
import matplotlib.pyplot as plt


# In[2]:


# Load the data from the output.csv file
filepath = r"C:\Users\DELL\source\repos\Project1\output.csv"
df = pd.read_csv(filepath)


# In[3]:


# Extract the x and y coordinates from the DataFrame
x = df['mean_dist_day'].values
y = df['mean_over_speed_perc'].values


# In[4]:


# Extract the cluster numbers
clusters = df['cluster'].values
# Define the colors for each cluster
colors = ['red', 'blue', 'green', 'black']


# In[7]:


# Plot the data using a scatter plot
fig, ax = plt.subplots(figsize=(8, 6))
for i in range(len(clusters)):
    ax.scatter(x[i], y[i], c=colors[clusters[i]])
ax.set_title('Clustered : mean_dist_day(y) vs mean_over_speed_perc(x)')
ax.set_xlabel('mean_over_speed_perc')
ax.set_ylabel('mean_dist_day')
ax.legend("0,1,2")
plt.show()


# # Q2)

# In[9]:


# Load the data from the output.csv file
filepath1 = r"C:\Users\DELL\source\repos\A1\output.csv"
df1 = pd.read_csv(filepath1)


# In[11]:


# Extract the x and y coordinates from the DataFrame
x = df1['Annual Income (k$)'].values
y = df1['Spending Score (1-100)'].values


# In[12]:


# Extract the cluster numbers
clusters = df['cluster'].values
# Define the colors for each cluster
colors = ['red', 'blue', 'green', 'orange', 'purple']


# In[13]:


# Plot the data using a scatter plot
fig, ax = plt.subplots(figsize=(8, 6))
for i in range(len(clusters)):
    ax.scatter(x[i], y[i], c=colors[clusters[i]])
ax.set_title('Clustered : spending(y) vs income(x)')
ax.set_xlabel('Annual Income (k$)')
ax.set_ylabel('Spending Score(1-100)')
ax.legend("0,1,2")
plt.show()

