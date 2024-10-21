module wheel(){
    r_wheel = 12;
    $fn=100;
    color("Gray"){
        rotate([90,0,90]){
            difference(){
                cylinder(5,r_wheel,r_wheel);
                translate([0,0,-1]){
                    cylinder(7,1.6,1.6);
                }
            }
        }
    }
}

wheel();