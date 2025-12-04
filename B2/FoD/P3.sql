-- 1
SELECT * FROM orders WHERE order_date > "2006-03-24" ORDER BY order_date ASC;
-- 2
DROP VIEW IF EXISTS sale_per_order; -- for testing purposes
-- SUM: because an order can have many products
CREATE VIEW sale_per_order AS
SELECT P.product_code, R.unit_price, R.quantity, R.unit_price * R.quantity * (1 - R.discount) AS value
FROM order_details AS R INNER JOIN products AS P ON R.product_id = P.id
WHERE R.order_id = 31;
-- 3 & 4
DROP VIEW IF EXISTS order_subtotals;
CREATE VIEW order_subtotals AS
SELECT R.id, R.order_date, C.company, SUM(RD.unit_price * RD.quantity * (1 - RD.discount)) AS subtotal
FROM customers AS C INNER JOIN orders AS R ON C.id = R.customer_id -- after each join, put the ON clause immediately!
INNER JOIN order_details AS RD ON R.id = RD.order_id
WHERE R.order_date > "2006-03-24"
GROUP BY R.id;
-- 5
SELECT * FROM order_subtotals HAVING subtotal >= 800; -- WHERE is fine here too
-- 6
DROP VIEW IF EXISTS employee_sales;
CREATE VIEW employee_sales AS
SELECT CONCAT(E.first_name, " ", E.last_name) AS full_name, SUM(RD.unit_price * RD.quantity * (1 - RD.discount)) AS sale_in_dollars
FROM employees AS E INNER JOIN orders AS R ON E.id = R.employee_id
INNER JOIN order_details AS RD ON R.id = RD.order_id
GROUP BY E.id
HAVING sale_in_dollars > 1000 -- WHERE is NOT fine here since WHERE is processed before SELECT. Also, HAVING goes after GROUP BY
ORDER BY sale_in_dollars DESC;
-- 7
SELECT DISTINCT category FROM products ORDER BY category ASC;
-- 8
SELECT MIN(standard_cost) AS min,
MAX(standard_cost) AS max,
AVG(standard_cost) AS average,
STDDEV(standard_cost) AS standard_deviation,
VARIANCE(standard_cost) AS variance
FROM products;
-- 9
DROP VIEW IF EXISTS category_avg_price;
CREATE VIEW category_avg_price AS
SELECT category, AVG(list_price) AS avg_list_price FROM products GROUP BY category; -- ORDER BY 
-- 10
SELECT ship_city, AVG(shipping_fee), MAX(shipping_fee) FROM orders GROUP BY ship_city ORDER BY ship_city ASC;
-- 11
DROP PROCEDURE IF EXISTS top_n;
DELIMITER //
CREATE PROCEDURE top_n (IN n INT)
BEGIN
	DECLARE n0 INT DEFAULT n;
	SELECT * FROM category_avg_price ORDER BY avg_list_price DESC LIMIT n0; -- LIMIT only accepts integer literal, so variable "n" is rejected
END //
DELIMITER ;
CALL top_n(5); -- calling procedure to make sure it works
-- 12
SELECT * FROM category_avg_price WHERE avg_list_price = (SELECT MIN(avg_list_price) FROM category_avg_price);
-- 13
SELECT PO.id, CONCAT(C.first_name, ' ', C.last_name) AS creator_name, CONCAT(A.first_name, ' ', A.last_name) AS approver_name
FROM purchase_orders AS PO
INNER JOIN employees AS C ON PO.created_by = C.id
INNER JOIN employees AS A ON PO.approved_by = A.id;
-- 14
DROP VIEW IF EXISTS partners;
CREATE VIEW partners AS
SELECT company, CONCAT(first_name, " ", last_name) AS full_name, email_address, "C" AS type FROM customers
UNION ALL
SELECT company, CONCAT(first_name, " ", last_name) AS full_name, email_address, "S" AS type FROM suppliers
ORDER BY company;
-- 15
SELECT POD.product_id, P.product_code, P.product_name
FROM products AS P INNER JOIN purchase_order_details AS POD ON P.id = POD.product_id
WHERE NOT EXISTS 
(SELECT NULL -- only the WHERE clause below is actually important. No need to select anything here.
FROM order_details AS OD
WHERE P.id = OD.product_id);
