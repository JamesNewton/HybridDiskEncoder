// title      : STGC Encoder Disk
// author     : James Newton
// license    : MIT License
// revision   : 0.003
// tags       : encoder, grey code, single track, STGC
// file       : stgc_wheel.jscad

//p is starting keyword as a string of binary digits. e.g. "1110"
//s is the sequence as an arraw
//d distance between sensors
function stgc(s, p, d) {
    let l=p.length; //number of sensors
    if (isNaN(d)) {
        dh=Math.ceil(s.length/w.value.length);
        d=1;
    }
    else {
        dh=d;
    }
    let fail=1;
    let v,b=0;
    for(;d<=dh && (fail>0);d++) {
        console.log('length:'+l+'<br>reading:position<br>'+p+':0')
        let m=[]; 
        for(let i=0;i<=s.length*l;i++) { 
            m[i]='_';
        }
        fail=0;
        for(var i=0;i<s.length;i++) {
            for (var j=0;j<l;j++){
                v=j*(d)+i;
                b=p.substr(j,1);
                if (m[v]!='_' && m[v]!=b) {
                        m[v]='x';
                        if (v<s.length*l) {
                            fail=v+1;
                            i=s.length;
                            console.log('length:'+d+' fails at:'+fail);
                        }
                } 
                else {
                    m[v]=b;
                    
                }
            }
        v=parseInt(s[i]);
        b=p.substr(v,1);
        p=p.substring(0,v)+(b=='0'?'1':'0')+p.substr(v+1,9);
        }
    }
    console.log('fail is:'+fail);
    if (fail>0) {
        alert('Fails at '+(fail-1));
    }
}

function main () {
  return union(
    difference(
      cube({size: 3, center: true}),
      sphere({r: 2, center: true})
    ),
    intersection(
      sphere({r: 1.3, center: true}),
      cube({size: 2.1, center: true})
    )
  ).translate([0, 0, 1.5]).scale(10);
}
