<?php 
define('DB_HOST', 'localhost'); 
define('DB_USERNAME', 'id18817195_gps'); 
define('DB_PASSWORD', 'gnT~E[c>1riY#=y+'); 
define('DB_NAME', 'id18817195_gps_db');

date_default_timezone_set('Asia/Karachi');

// Connect with the database 
$db = new mysqli(DB_HOST, DB_USERNAME, DB_PASSWORD, DB_NAME); 
 
// Display error if failed to connect 
if ($db->connect_errno) { 
    echo "Connection to database is failed: ".$db->connect_error;
    exit();
}