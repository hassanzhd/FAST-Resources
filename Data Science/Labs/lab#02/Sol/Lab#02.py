#!/usr/bin/env python
# coding: utf-8

# In[1]:


#Q1a
import pandas as pd
df1 = pd.read_csv("data1.csv", index_col=0)
print(df1)
df2 = pd.read_csv("data2.csv", index_col=1)
print(df2)


# In[2]:


#Q1b
df3 = pd.concat([df1, df2])
print(df3)


# In[3]:


#Q1c
df4 = pd.read_csv("data3.csv", index_col=0)
print(df4)
df5 = pd.concat([df3, df4], axis=1)
print(df5)


# In[4]:


#Q1d
df6 = pd.read_json("data.json")
# print(df6)
df7 = pd.concat([df5, df6], axis=0)
print(df7)


# In[5]:


#Q1e
import numpy as np
# df7 = df7.replace('Hello', np.nan)
# df7 = df7.replace(r'^[a-zA-Z]', np.nan, regex=True)
# df7
df7 = df7.apply(pd.to_numeric,errors="coerce")
df7


# In[6]:


#Q1f
df7 = df7.fillna(df7.mean())
df7


# # Dropping Columns in a DataFrame

# In[7]:


#Q2
df = pd.read_csv('BL-Flickr-Images-Book.csv')
df.head()


# In[8]:


to_drop = ['Edition Statement',
            'Corporate Author',
            'Corporate Contributors',
            'Former owner',
            'Engraver',
            'Contributors',
            'Issuance type',
            'Shelfmarks']

df = df.drop(to_drop, axis=1)


# In[9]:


df.head()


# # Changing the Index of a DataFrame

# In[10]:


df['Identifier'].is_unique #to check if all identifies are uniques, can be used to check uniqueness if we want to make it index


# In[11]:


df = df.set_index('Identifier')
df.head()


# In[12]:


df.loc[206]


# # Tidying up Fields in the Data

# In[13]:


df.dtypes.value_counts() # df.get_dtypes_counts() is deprecated


# In[14]:


df.loc[1905:, 'Date of Publication'].head(10)


# In[15]:


extr = df['Date of Publication'].str.extract(r'^(\d{4})', expand=False)
extr.head()


# In[16]:


df['Date of Publication'] = pd.to_numeric(extr)
df['Date of Publication'].dtype


# In[17]:


df['Date of Publication'].isnull().sum() / len(df) #to check how many values are null in the column


# In[18]:


df.loc[4157862]


# In[19]:


df.loc[4159587]


# In[20]:


pub = df['Place of Publication']
london = pub.str.contains('London') #will make rows with string 'London' True
london[:5] #print from 0 till 5th index


# In[21]:


oxford = pub.str.contains('Oxford')
oxford[:10]


# # Combining str Methods with NumPy to Clean Columns

# In[22]:


df['Place of Publication'].head(10)


# In[23]:


df['Place of Publication'] = np.where(london, 'London',
                                     np.where(oxford, 'Oxford', pub.str.replace('-',' ')))
df['Place of Publication'].head(10)


# # Cleaning the Entire Dataset Using the applymap Function

# In[24]:


university_towns = []
with open('university_towns.txt') as file:
    for line in file:
        if '[edit]' in line:
            #remember this state until next is found
            state = line
        else:
            # Otherwise, we have a city; keep state as last-seen
            university_towns.append((state, line))
            
university_towns[:5]


# In[25]:


towns_df = pd.DataFrame(university_towns, columns=["State", "Region_Name"])


# In[26]:


towns_df.head(10)


# In[27]:


def get_citystate(item):
    if ' (' in item:
        return item[:item.find(' (')]
    elif '[' in item:
        return item[:item.find('[')]
    else:
        return item


# In[30]:


towns_df =  towns_df.applymap(get_citystate)


# In[31]:


towns_df.head(10)


# # Renaming Columns and Skipping Rows

# In[34]:


olympics_df = pd.read_csv('olympics.csv')
olympics_df.head()


# In[40]:


olympics_df.loc[0]
#rough work
#search for apply() vs applymap()
#search for iloc[] vs loc[]


# In[41]:


olympics_df = pd.read_csv('olympics.csv', header=1)
olympics_df.head()


# In[42]:


new_names =    {'Unnamed: 0': 'Country',
                '? Summer': 'Summer Olympics',
                '01 !': 'Gold',
                '02 !': 'Silver',
                '03 !': 'Bronze',
                '? Winter': 'Winter Olympics',
                '01 !.1': 'Gold.1',
                '02 !.1': 'Silver.1',
                '03 !.1': 'Bronze.1',
                '? Games': '# Games',
                '01 !.2': 'Gold.2',
                '02 !.2': 'Silver.2',
                '03 !.2': 'Bronze.2'}
olympics_df = olympics_df.rename(columns=new_names)


# In[43]:


olympics_df.head()


# In[ ]:




