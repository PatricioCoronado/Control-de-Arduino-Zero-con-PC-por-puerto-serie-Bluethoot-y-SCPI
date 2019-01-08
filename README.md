Conectar y controlar un Arduino Zero mediante puerto serie por Bluethoot y SCPI.
El objetivo es hacer una prueba de concepto conectando un PC con un Arduino Zero a través del puerto serie por Bluetooth en la 
capa física.

En la capa de datos se utiliza la librería Segainvex_SCPI_Serial. https://github.com/PatricioCoronado/segainvex_scpi_Serial
Mediante esta librería el PC puede enviar comandos con parámetros a Arduino. Este responde ejecutando una función para ese 
comando y lee los parámetros. También puede devolver valores al PC. Esto resulta muy util para hacer instrumentación virtual.

En el PC se puede instalar la aplicación PlantillaCVI, para enviar comandos con o sin parámetros y recibir datos de Arduino. Para
que se ejecute la aplicación en el PC hay que instalar previamente el runtime engine de LabWindows/CVI de National Instruments:
http://www.ni.com/es-es/support/downloads/software-products/download.labwindows-cvi-runtime.html .

