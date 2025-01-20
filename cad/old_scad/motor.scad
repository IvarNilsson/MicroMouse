module motor(){
    // Housing
    color("LightCyan"){
        translate([6,0,0]){
            cube([23,12,10]);
        }
    }
    color("Cyan"){
        difference() {
            translate([29,0,0]){
                cube([1.1,12,10]);
            }
            translate([28.8,9.8,7.8]){
                rotate([0,90,0]){
                    $fn=25;
                    cylinder(1.4,1.4,1.4);
                }
            }
            translate([28.8,2.2,2.2]){
                rotate([0,90,0]){
                    $fn=25;
                    cylinder(1.4,1.4,1.4);
                }
            }
          }
    }
        
    // PCB+Hall sensor
    color("Green"){
        translate([2,0,0]){
            cube([4,12,18]);
        }
        rotate([0,90,0]){
            translate([-5,6,0]){
                $fn=100;
                cylinder(2,4.6,4.6);
            }
        }
    }
    
    // Shaft
    color("Silver"){
        difference() {
            translate([30,6,5]){
                rotate([0,90,0]){
                    $fn=100;
                    cylinder(10,1.5,1.5);
                }
            }
            translate([31,7,3.5]){
                cube([9.1,2,3]); 
            }
        }
    }
}

motor();
