<?php
//error: Google Maps JavaScript API error: ApiNotActivatedMapError
//solution: click "APIs and services" Link
//			click "Enable APIs and services" button
//			Select "Maps JavaScript API" then click on enable

require 'config.php';

$sql = "SELECT * FROM tbl_gps WHERE 1";
$result = $db->query($sql);
if (!$result) {
  { echo "Error: " . $sql . "<br>" . $db->error; }
}

$rows = $result -> fetch_all(MYSQLI_ASSOC);


//header('Content-Type: application/json');
//echo json_encode($rows);


?>
<html>
<head>
<title>Add Markers to Show Locations in Google Maps</title>
</head>
<style>
body {
	font-family: Arial;
}

#map-layer {
	margin: 20px 0px;
	max-width: 1300px;
	min-height: 650;
}
</style>
<body>
	<h1>Add Markers to Show Locations in Google Maps</h1>
	<div id="map-layer"></div>

	<script
		src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCtjS6hmru0Iwbs9R01kj6ne--19diXizc&callback=initMap"
		async defer></script>
		
    <script>
    var map;
    var gps_path_coordinates=Array();
    
    function initMap() 
    {
        
        var mapLayer = document.getElementById("map-layer");
		var centerCoordinates = new google.maps.LatLng(44.43502165849305, 26.102333525991632);
		var defaultOptions = { center: centerCoordinates, zoom: 10 }
		map = new google.maps.Map(mapLayer, defaultOptions);
        
        <?php foreach($rows as $location){ ?>
        var php_location = new google.maps.LatLng(<?php echo $location['lat']; ?>, <?php echo $location['lng']; ?>);
        gps_path_coordinates.push({
            lat:<?php echo $location['lat']; ?>,
            lng:<?php echo $location['lng']; ?>
        });
        
        var Marker={
            coords:php_location,
            content:  'Time when tracked: <?php echo $location['date']; ?> '
        }
        addMarker(Marker);
        
        /*var marker = new google.maps.Marker({
            position: php_location,
            map: map
        }); 
        */
        
         
        <?php } ?>
        gps_path=new google.maps.Polyline({
			path : gps_path_coordinates,
			geodesic : true,
			strokeColor : '#FF0000',
			strokeOpacity : 1,
			strokeWeight : 4,
			map : map
		});
        gps_path.setMap(map);
    }
    
    
    function addMarker(props){
        var marker = new google.maps.Marker({
          position:props.coords,
          map:map,
          //icon:props.iconImage
        });

        // Check for customicon
        if(props.iconImage){
          // Set icon image
          marker.setIcon(props.iconImage);
        }

        // Check content
        if(props.content){
          var infoWindow = new google.maps.InfoWindow({
            content:props.content
          });

          marker.addListener('click', function(){
            infoWindow.open(map, marker);
          });
        }
      }
      
    </script>
    
    

</body>
</html>