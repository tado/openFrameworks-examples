varying vec3 normal;
varying vec4 position;
varying vec2 blah;


void main() {
	gl_Position = ftransform();
	position = gl_Vertex;
}
