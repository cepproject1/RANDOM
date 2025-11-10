salary = []

value=int(input("Enter no of employees"))

for i in range(value):
    s=float(input(f"Enter the salaries {i+1}:"))
    salary.append(s)


def selection_sort(arr):
    for i in  range(len(arr)):
        min_index = i
        for j in range(i+1,len(arr)):
            if arr[j]<arr[min_index]:
                min_index=j
            arr[i],arr[min_index]=arr[min_index],arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-i-1):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]

salaries=salary.copy()
selection_sort(salaries)
print("Salaries sorted using Selection Sort:", salaries)
print("Top 5 highest salaries:", salaries[-5:][::-1])

salaries = salary.copy()
bubble_sort(salaries)
print("\nSalaries sorted using Bubble Sort:", salaries)
print("Top 5 highest salaries:", salaries[-5:][::-1])



