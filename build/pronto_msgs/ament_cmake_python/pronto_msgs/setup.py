from setuptools import find_packages
from setuptools import setup

setup(
    name='pronto_msgs',
    version='0.3.0',
    packages=find_packages(
        include=('pronto_msgs', 'pronto_msgs.*')),
)
