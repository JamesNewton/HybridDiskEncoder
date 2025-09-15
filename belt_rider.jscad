// simple belt rider

function getParameterDefinitions() {
  return [
    { name: 'mnt_id_rad', type: 'float', initial: 1.5, caption: "mounting shaft radius:" },
    { name: 'mnt_od_rad', type: 'float', initial: 17, caption: "outer radius:" },
    { name: 'mnt_thick', type: 'float', initial: 38, caption: "mounting thickness:" },
    { name: 'mnt2ride', type: 'float', initial: 18, caption: "distance from mount to rider:" },
    { name: 'ride_id_rad', type: 'float', initial: 1.5, caption: "rider shaft radius:" },
    { name: 'belt_thick', type: 'float', initial: 16, caption: "belt thickness:" },
    { name: 'belt_clear', type: 'float', initial: 12.5, caption: "from plate to belt edge:" },
    { name: 'bear_od_rad', type: 'float', initial: 5, caption: "bearing outer radius:" },
    { name: 'bear_thick', type: 'float', initial: 12, caption: "bearing thickness:" },
    { name: 'bear_count', type: 'int', initial: 3, caption: "number of bearings:" },
{ name: 'output', type: 'choice', caption: 'Output:', values: [0, 1], captions: ["Assembly", "Parts"], initial: 0 }    ];
}

function main() {
    //thickness of the belt rider
    const ride_thick = params.bear_count * params.bear_thick
    //distance from mounting plate to near edge of belt
    const belt_clear_center = params.belt_clear - params.belt_thick / 2;
    //distance from plate to near edge of bearing slot
    const bear_slot_clear = params.belt_clear_center - ride_thick / 2;
    
    // ---- OBJECTS ---
    const bearing = 
      difference(
         cylinder({r:params.bear_od_rad, h:ride_thick, center: true}),
         cylinder({r:params.ride_id_rad, h:params.mnt_thick, center: true})
      )

    const bearing_space = 
      union(
         cylinder({r:params.bear_od_rad, h:ride_thick, center: true}),
         cylinder({r:params.ride_id_rad, h:params.mnt_thick, center: true})
      )

    return union(
        difference(
            linear_extrude({height:params.mnt_thick},
                hull(
                    circle({r:params.mnt_od_rad} ),
                    circle({r:params.mnt_od_rad / 2} )
                        .translate([
                            params.mnt_od_rad / 2,
                            -params.mnt2ride + params.mnt_od_rad / 2,
                            0
                        ])
                )
            ).translate([
                -params.mnt_od_rad,
                -params.mnt_od_rad,
                -params.mnt_thick/2]
                ),
            cylinder({r:params.mnt_id_rad, h: params.mnt_thick} )
            .translate([
                0,
                0,
                -params.mnt_thick/2]
                ),
            bearing_space.translate([
                params.mnt_od_rad * 0.3,-
                params.mnt2ride,
                0
                ])
            )
        ).translate([0,0,params.mnt_thick/2])
    }
