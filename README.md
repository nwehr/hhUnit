### Build Docker Image
`docker build -t ndunit ./`

### Run Container
`docker run --rm -t -v $(pwd)/test:/unit-tests ndunit`