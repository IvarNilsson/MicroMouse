module test_wheel(){
    translate([0,0,7]){
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
    color("DimGray"){
        translate([5,-5,-3.1]){
            cube([10,10,3]);
        }
        translate([5,-5,2.1]){
            cube([10,10,3]);
        }
    }
}
test_wheel();