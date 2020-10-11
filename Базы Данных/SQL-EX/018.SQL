SELECT DISTINCT maker, price
FROM Printer JOIN Product
ON Printer.model = Product.model
WHERE price =(SELECT MIN (price) FROM Printer WHERE color = 'y') AND color = 'y'
