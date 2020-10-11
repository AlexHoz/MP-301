SELECT Product.model, price
FROM Product JOIN PC
ON Product.model = PC.model
WHERE maker = 'B'
UNION
SELECT Product.model, price
FROM Product JOIN Laptop
ON Product.model = Laptop.model
WHERE maker = 'B'
UNION
SELECT Product.model, price
FROM Product JOIN Printer
ON Product.model = Printer.model
WHERE maker = 'B'
