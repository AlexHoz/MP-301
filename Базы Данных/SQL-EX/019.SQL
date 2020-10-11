SELECT maker, AVG (screen) AS 'Average Screen'
FROM Product JOIN Laptop
ON Product.model = Laptop.model
WHERE Laptop.model IN (SELECT model FROM Product WHERE type = 'Laptop')
GROUP BY maker
