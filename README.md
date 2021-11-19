# vulscancanaima
PROTOTIPO DE AUTOMATIZACION DE BUSQUEDA DE VULNERABILIDADES PARA DEPENDENCIAS Y PAQUETES INSTALADOS EN CANAIMA

Por ahora solo funciona con el archivo: paquetesinstalados.txt que debe ser requerido por otros medios por razones obvias

el archivo de dependencias y paquetes debe estar en la misma carpeta que el vulscancanaima.c, en caso contrario debe especificar 
la ruta en el primer argumento de la funcion fopen en la siguiente linea de codigo:

>> FILE *fichero= fopen("paquetesinstalados.txt",3.- "r");

compilacion:
  
      gcc vulscancanaima.c -o vulscancanaima
      
ejecucion:

      ./vulscancanaima
