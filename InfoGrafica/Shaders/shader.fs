#version 330
in vec4 vColor;
in vec3 normal;
in vec3 posFrag;
in vec2 uvFrag;
struct DirectionalLight{
    vec3 color;
    float ambientInten;
    vec3 lightDir;
    float diffuseInten;
};

uniform DirectionalLight directionalLight;
uniform vec3 cameraPos;
uniform float specularInten;
uniform float shininess;
uniform float time;

out vec4 colour;
void main(){
    vec3 norm = normalize(normal);
    vec3 lDir  = normalize(directionalLight.lightDir);
    vec3 viewDir = normalize(cameraPos - posFrag);

    //Ambient
    vec3 ambient = directionalLight.ambientInten * directionalLight.color;
    //Diffuse
    float diff = max(dot(norm, lDir), 0.0f);
    vec3 diffuse = directionalLight.color * directionalLight.diffuseInten * diff;
    //Specular
    vec3 halfWayVec = normalize(lDir + viewDir);
    float spec = pow(max(dot(norm, halfWayVec), 0.0f), shininess);
    vec3 specular = directionalLight.color * specularInten * spec;


    vec3 luzFinal = ambient + diffuse + specular;


    float vel = 0.9*10 + 0.1*(cos(time + posFrag.x * 100) + 1)/2;
    float val1 = (clamp((cos(time * vel + posFrag.y*10)+1)/2, 0.9, 1) + 0.1);
    float val2 = (clamp((cos(time * vel*3 + posFrag.y*100)+1)/2, 0.9, 1) + 0.1);
    colour = vec4(uvFrag.x, uvFrag.y, 0, 1 )*val1*val2 * vec4(luzFinal, 1.0); 
}