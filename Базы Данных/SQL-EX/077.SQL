WITH Dates(trip_no, date) AS(
SELECT DISTINCT trip.trip_no, date
FROM trip inner join pass_in_trip on trip.trip_no = pass_in_trip.trip_no
WHERE town_from = 'Rostov'
) 

SELECT COUNT(1), date
FROM Dates
GROUP BY date
HAVING COUNT(trip_no) IN (SELECT DISTINCT MAX(b) FROM (SELECT COUNT(*) FROM Dates GROUP BY date) a(b))
