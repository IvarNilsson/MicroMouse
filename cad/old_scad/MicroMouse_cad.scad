use <mouse_body.scad>
use <bump.scad>
use <wheel.scad>
use <motor.scad>
use <test_wheel.scad>

module ground(){
    grund_clearance = 5;
    color("YellowGreen"){
        translate([0,0,-grund_clearance-1]){
            cube([100,100,1]);
        }
    }
}
// END MODULES

mouse_body();

// ADD MOTORS
translate([40,40,2]){ // FRONT motor
    motor();
}
translate([60,36,2]){ // REAR motor
    rotate([180,180,0]){
        motor();
    }
}
// ADD WHEELS
translate([20,30,7]){
    wheel();
}
translate([75,30,7]){
    wheel();
}
// ADD BUMP
translate([50,70,0]){
    bump();
}

ground();

translate([20,30,0]){
    //test_wheel();
}
translate([80,30,0]){
    rotate([180,180,0]){
        //test_wheel();
    }
}

//import_motor();
