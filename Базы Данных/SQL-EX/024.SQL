WITH prices AS
(
  SELECT model, price
  FROM pc
  UNION
  SELECT model, price
  FROM laptop
  UNION
  SELECT model, price
  FROM printer
),
max_price AS
(
  SELECT MAX(price) AS max_price
  FROM prices
)

SELECT model
FROM prices
WHERE price IN
(
  SELECT * FROM max_price
)
