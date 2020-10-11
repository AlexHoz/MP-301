SELECT maker
FROM PC JOIN Product
ON PC.model = Product.model
WHERE speed >= 750
INTERSECT
SELECT maker
FROM Laptop JOIN Product
ON Laptop.model = Product.model
WHERE speed >= 750
