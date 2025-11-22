// simple belt rider

function getParameterDefinitions() {
  return [
    { name: 'mnt_id_rad', type: 'float', initial: 2, caption: "mounting shaft radius:" },
    { name: 'mnt_od_rad', type: 'float', initial: 15, caption: "outer radius:" },
    { name: 'mnt_thick', type: 'float', initial: 20, caption: "mounting thickness:" },
    { name: 'mnt2ride', type: 'float', initial: 25, caption: "distance from mount to rider:" },
    { name: 'ride_id_rad', type: 'float', initial: 2.6, caption: "rider shaft radius:" },
    { name: 'belt_thick', type: 'float', initial: 16, caption: "belt thickness:" },
    { name: 'belt_clear', type: 'float', initial: 12.5, caption: "from plate to belt edge:" },
    { name: 'bear_od_rad', type: 'float', initial: 5, caption: "bearing outer radius:" },
    { name: 'bear_thick', type: 'float', initial: 4, caption: "bearing thickness:" },
    { name: 'bear_count', type: 'int', initial: 3, caption: "number of bearings:" },
{ name: 'output', type: 'choice', caption: 'Output:', values: [0, 1], captions: ["Assembly", "Print"], initial: 0 }    ];
}

function main() {
    //multiplier for clearance allowance
    const allowance = 1.1
    //thickness of the belt rider
    const ride_thick = params.bear_count * params.bear_thick
    //extra distance from mounting plate to near edge of bearings
    const bear_extra = (params.belt_thick - ride_thick) / 2
    
    // ---- OBJECTS ---
    let bearing
    console.log(params.output)
    if (params.output==0) { //visualize assembly
    bearing = 
      union(
         cylinder({r:params.bear_od_rad, h:ride_thick, center: true}),
         cylinder({r:params.ride_id_rad*1.1, h:params.mnt_thick*1.1, center: true})
      ).setColor(css2rgb('silver'))
    } else { //support or better yet, nothing.
    bearing = 
        difference(
         cylinder({
             r:params.ride_id_rad, 
             h:ride_thick-0.2, 
             center: true
         }),
         cylinder({r:params.ride_id_rad*allowance, h:params.mnt_thick*1.1, center: true})
         )
    }

    const bearing_space = 
      union(
         cylinder({r:params.bear_od_rad*1.1, h:ride_thick, center: true}),
         cylinder({
            r:params.ride_id_rad*allowance, 
            h:params.mnt_thick * 2 + bear_extra, 
            center: true
             
         })
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
            cylinder({r:params.mnt_id_rad*allowance, h: params.mnt_thick} )
            .translate([
                0,
                0,
                -params.mnt_thick/2]
                ),
            bearing_space.translate([
                params.mnt_od_rad * 0.4 - params.ride_id_rad * 1.2 - 0.2,-
                params.mnt2ride - params.mnt_od_rad / 3 + params.ride_id_rad,
                bear_extra
                ])
            )
        , bearing.translate([
                params.mnt_od_rad * 0.4 - params.ride_id_rad * 1.2 - 0.2,-
                params.mnt2ride - params.mnt_od_rad / 3 + params.ride_id_rad,
                bear_extra
                ])
        ).translate([0,0,params.mnt_thick/2])
    }
    
    
    
    
    
    
    
    
    
