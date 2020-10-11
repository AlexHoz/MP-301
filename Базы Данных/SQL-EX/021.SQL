SELECT maker, MAX(price) AS Max_price
FROM PC JOIN Product
ON PC.model = Product.model
GROUP BY maker
