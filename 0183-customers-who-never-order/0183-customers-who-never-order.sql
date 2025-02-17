/* Write your PL/SQL query statement below */
select Customers.name as Customers from customers left outer join orders on customers.id = orders.customerId where orders.id is NULL;