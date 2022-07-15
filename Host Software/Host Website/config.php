<?php 
define('DB_HOST', 'localhost:3306'); 
define('DB_USERNAME', 'root'); 
define('DB_PASSWORD', '123456'); 
define('DB_NAME', 'gps_coordinates');

date_default_timezone_set('Europe/Bucharest');

// Connect with the database 
$db = new mysqli(DB_HOST, DB_USERNAME, DB_PASSWORD, DB_NAME); 
 
// Display error if failed to connect 
if ($db->connect_errno) { 
    echo "Connection to database is failed: ".$db->connect_error;
    exit();
}