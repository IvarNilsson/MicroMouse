module mouse_body(){

    h = 2; //PCB height

    // main body
    translate([25, 0,0]){
        cube([50,5,h]);
    }
    translate([20, 5,0]){
        cube([60,13,h]);
    }
    translate([25, 18,0]){
        cube([50,24,h]);
    }
    translate([20, 42,0]){
        cube([60,18,h]);
    }
    // rounded edges
    module rounded_edge(){
        cylinder(h,5,5);
    }
    translate([25, 5,0]){
        //circle(5);
        rounded_edge();
    }
    translate([75, 5,0]){
        //circle(5);
        rounded_edge();
    }
    
    // top
    difference(){
        translate([50,60,0]){
            //circle(30);
            cylinder(h,30,30);
        }
        translate([50,70,0]){
            $fn=25;
            cylinder(4,1.1,1.1);
        }
    }
}
mouse_body();