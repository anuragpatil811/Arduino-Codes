create database k;
use k;

CREATE TABLE Points (
    Point_ID INT PRIMARY KEY,
    X DECIMAL(10, 2),
    Y DECIMAL(10, 2),
    Cluster_ID INT  
);

INSERT INTO Points (Point_ID, X, Y)
VALUES 
(1, 2.0, 3.0),
(2, 5.0, 8.0),
(3, 1.5, 1.7),
(4, 8.0, 5.5),
(5, 7.2, 6.8),
(6, 3.1, 3.3),
(7, 9.0, 8.0),
(8, 4.2, 2.9),
(9, 6.4, 5.9),
(10, 3.5, 4.0);

CREATE TABLE Centroids (
    Cluster_ID INT PRIMARY KEY,
    X DECIMAL(10, 2),
    Y DECIMAL(10, 2)
);
INSERT INTO Centroids (Cluster_ID, X, Y)
VALUES 
(1, 2.0, 3.0),
(2, 8.0, 5.5);
UPDATE Points
SET Cluster_ID = (
    SELECT Cluster_ID
    FROM Centroids
    ORDER BY SQRT(POWER(Points.X - Centroids.X, 2) + POWER(Points.Y - Centroids.Y, 2)) ASC
    LIMIT 1
);

UPDATE Centroids
SET X = (SELECT AVG(P.X) FROM Points P WHERE P.Cluster_ID = 1),
    Y = (SELECT AVG(P.Y) FROM Points P WHERE P.Cluster_ID = 1)
WHERE Cluster_ID = 1;


UPDATE Centroids
SET X = (SELECT AVG(P.X) FROM Points P WHERE P.Cluster_ID = 2),
    Y = (SELECT AVG(P.Y) FROM Points P WHERE P.Cluster_ID = 2)
WHERE Cluster_ID = 2;


UPDATE Points
SET Cluster_ID = (
    SELECT Cluster_ID
    FROM Centroids
    ORDER BY SQRT(POWER(Points.X - Centroids.X, 2) + POWER(Points.Y - Centroids.Y, 2)) ASC
    LIMIT 1
);


UPDATE Centroids
SET X = (SELECT AVG(P.X) FROM Points P WHERE P.Cluster_ID = 1),
    Y = (SELECT AVG(P.Y) FROM Points P WHERE P.Cluster_ID = 1)
WHERE Cluster_ID = 1;


UPDATE Centroids
SET X = (SELECT AVG(P.X) FROM Points P WHERE P.Cluster_ID = 2),
    Y = (SELECT AVG(P.Y) FROM Points P WHERE P.Cluster_ID = 2)
WHERE Cluster_ID = 2;


