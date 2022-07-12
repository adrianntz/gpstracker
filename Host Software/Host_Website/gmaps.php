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



 <!doctype html>
<html lang="en">
   <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
        <meta name="description" content="" />
        <meta name="author" content="" />
        <title>Grayscale - Start Bootstrap Theme</title>
        <link rel="icon" type="image/x-icon" href="assets/favicon.ico" />
        <!-- Font Awesome icons (free version)-->
        <script src="https://use.fontawesome.com/releases/v6.1.0/js/all.js" crossorigin="anonymous"></script>
        <!-- Google fonts-->
        <link href="https://fonts.googleapis.com/css?family=Varela+Round" rel="stylesheet" />
        <link href="https://fonts.googleapis.com/css?family=Nunito:200,200i,300,300i,400,400i,600,600i,700,700i,800,800i,900,900i" rel="stylesheet" />
        <!-- Core theme CSS (includes Bootstrap)-->
        <link href="css/styles.css" rel="stylesheet" />
		
    </head>
	
	
<style>
body {
	font-family: Arial;
}

#map-layer {
	margin: 20px 0px;
	max-width: 100vw;
	min-height: 90vh;
}
</style>
<body style="background-color:black">

	
	<div id="map-layer"></div>

	<script
		src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCtjS6hmru0Iwbs9R01kj6ne--19diXizc&callback=initMap"
		async defer></script>
		
    <script>
    var map;
	var markers=Array();
    var gps_path_coordinates=Array();
    
    function initMap() 
    {
		
        var last_location = new google.maps.LatLng(<?php echo end($rows)['lat']; ?>, <?php echo end($rows)['lng']; ?>); 
        var mapLayer = document.getElementById("map-layer");
		//var centerCoordinates = new google.maps.LatLng(44.43502165849305, 26.102333525991632);
		var centerCoordinates= last_location;
		var defaultOptions = { center: centerCoordinates, zoom: 15 }
		map = new google.maps.Map(mapLayer, defaultOptions);
        
        <?php foreach($rows as $location){ ?>
        var php_location = new google.maps.LatLng(<?php echo $location['lat']; ?>, <?php echo $location['lng']; ?>);
        gps_path_coordinates.push({
            lat:<?php echo $location['lat']; ?>,
            lng:<?php echo $location['lng']; ?>
        });
        
        var Marker={
            coords:php_location,
            content: ' <p> Time when tracked: <?php echo $location['date']; ?> </p> <p> Lat: <?php echo $location['lat']; ?> </p> <p> Lng: <?php echo $location['lng']; ?> </p> '
        }
        addMarker(Marker);
        cycleThroughMarkers(markers);
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
			strokeOpacity : 0.6,
			strokeWeight : 6,
			map : map
		});
        gps_path.setMap(map);
    }
    
    
    function addMarker(props){
        var marker = new google.maps.Marker({
          position:props.coords,
		  animation: google.maps.Animation.DROP,
          map:map,
          //icon:props.iconImage
        });
		 markers.push(marker);
		 map.setCenter(marker.getPosition());
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

          marker.addListener('click', function()
		  {
            infoWindow.open(map, marker);
			 if (marker.getAnimation() !== null) 
			  {
				marker.setAnimation(null);
			  } else 
			  {
				marker.setAnimation(google.maps.Animation.BOUNCE);
				marker.setAnimation(null);//by setting the animation null, we oly run the animation once
			  }
          });
        }
		
      }
	  
	function cycleThroughMarkers(markerarray)
	{
		for(let i=0;i<markerarray.length;i++)
		{
			markerarray[i].setMap(null);
			markerarray[i].setMap(map);
		}
	}
      
    </script>
	<div class="container px-4 px-lg-5 d-flex h-100 align-items-center justify-content-center">
                <div class="d-flex justify-content-center">
                    <div class="text-center">
                         <a class="btn btn-danger" href="http://localhost/index.html">Back      </a>
                    </div>
                </div>
            </div>
   
    

    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">

  </head>
  <body>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
  </body>
</html>
</body>
</html>