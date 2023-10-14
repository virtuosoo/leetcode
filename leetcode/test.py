import numpy as np
import pandas as pd
data = pd.read_csv('HistoricalPrices.csv')
data['Date'] = pd.to_datetime(data['Date'])
data.sort_values(by='Date', inplace=True)
data = data.reset_index()
lists = [5, 10, 20, 40, 60, 120, 240]
for value in lists:
    data['MA_{}'.format(value)] = data[' Close'].rolling(value).mean()
data[data.columns[1:]].tail()
data['Date'] = pd.to_datetime(data['Date'])
def strategy(data, ma=5, b=0, d=3, f=5):
    upper = data['MA_{}'.format(ma)] * (1 + b)
    lower = data['MA_{}'.format(ma)] * (1 - b)
    status = 0 # 初始状态为未持用
    test_d = 0
    last_op_day = 0
    for i in range(len(upper)-5+1): 
        # print('{}-th day'.format(i))
        day = i + 4
        temp_upper = upper.loc[day]
        temp_lower = lower.loc[day]
        temp_price = data[' Close'].loc[day]
        if status == 0:
            if temp_price > temp_upper:
                test_d = test_d + 1
            else:
                test_d = 0
            if (test_d == d) & (day - last_op_day >= f):
                last_op_day = day
                print('{}-th day'.format(i))
                print('buy')
                test_d = 0
                status = 1
        elif status == 1:
            if temp_price < temp_lower:
                test_d = test_d - 1
            else:
                test_d = 0
            if (test_d == -d) & (day - last_op_day >= f):
                last_op_day = day
                print('{}-th day'.format(i))
                print('sell')
                test_d = 0
                status = 0    