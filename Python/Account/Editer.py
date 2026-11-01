import pandas as pd

df = pd.read_csv("C:/Users/WIN11/Desktop/code/TheCode/Python/Account/data.csv")

# ยอดรวมทั้งหมด
print(df["price"].sum())

# ยอดรวมแยกตามหมวด
print(df.groupby("category")["price"].sum())

# รายการที่แพงที่สุด
print(df.loc[df["price"].idxmax()])

# สร้างคอลัมน์วันที่จาก day + month (ใส่ปีเอง)
df["date"] = pd.to_datetime(
    dict(year=2026, month=df["month"], day=df["day"])
)

# กรองเฉพาะ food ที่ราคามากกว่า 750
print(df[(df["category"] == "food") & (df["price"] > 750)])