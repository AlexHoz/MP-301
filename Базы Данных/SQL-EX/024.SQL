WITH UNITED AS
(
SELECT model, price
FROM PC

UNION

SELECT model, price
FROM Laptop

UNION

SELECT model, price
FROM Printer
)
SELECT model
FROM UNITED
WHERE price = (
SELECT MAX (price) AS max_price
FROM UNITED )
