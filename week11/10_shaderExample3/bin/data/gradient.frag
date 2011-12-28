
varying vec4 position;

uniform float mousex;
uniform float mousey;

//uniform float color;

void main() {
	vec3 pixelpos = vec3(position.x, position.y, position.z);
	vec3 mousepos = vec3(mousex, mousey, 50.0);
	float dist = distance(pixelpos, mousepos);
	float val = 0.0;
	//if (dist < a){
		val = 1.0 - dist/100.0;
	//}
	gl_FragColor = vec4 (val*0.2, val*0.5, val,1);
	
}
