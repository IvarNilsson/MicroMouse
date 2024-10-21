module bump(){
    difference(){
        $fn=25;
        sphere(3);
        translate([-5,-5,0]){
            cube([10,10,5]);
        }
    }
    $fn=25;
    cylinder(3,1,1);
}

bump();