import logging
import torch
import os
from log_helper import logger_init
class Config():
    
    """
    基于Transformer架构的类Translation模型配置类
    """

    def __init__(self):

        self.train_corpus_file_paths = ['D:\\MyCode\\Python_code\\Transformer\\data\\train.de',
                                        'D:\\MyCode\\Python_code\\Transformer\\data\\train.en']
        self.val_corpus_file_paths = ['D:\\MyCode\\Python_code\\Transformer\\data\\val.de',
                                        'D:\\MyCode\\Python_code\\Transformer\\data\\val.en']
        self.test_corpus_file_paths = ['D:\\MyCode\\Python_code\\Transformer\\data\\test_2016_flickr.de',
                                       'D:\\MyCode\\Python_code\\Transformer\\data\\test_2016_flickr.en']
        self.min_freq = 1
        self.batch_size = 128
        self.d_model = 512
        self.num_head = 8
        self.num_encoder_layers = 6
        self.num_decoder_layers = 6
        self.dim_feedforward = 512
        self.dropout = 0.1
        self.beta1 = 0.9
        self.beta2 = 0.98
        self.epsilon = 10e-9
        self.device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')
        self.epochs = 10
        self.model_save_dir = os.path.join('D:\\MyCode\\Python_code\\Transformer', 'cache')
        if not os.path.exists(self.model_save_dir):
            os.makedirs(self.model_save_dir)
        # 日志相关
        logger_init(log_file_name='log_train',
                    log_level=logging.INFO,
                    log_dir=self.model_save_dir)